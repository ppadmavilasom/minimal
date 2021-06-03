#!/bin/sh
# make a jwt token signed with provided private key
CLAIMS_FILE=${1:-claims/example_claim.json}
DURATION=${2:-600}
PRIVATE_KEY=${3:-privateKey.pem}
HEADER='{"kid":"/privateKey.pem","typ":"JWT","alg":"RS256"}'

# header
jwt_header=$(echo "$HEADER" | tr -d '\r\n' | base64 | sed s/\+/-/g | sed 's/\//_/g' | sed -E s/=+$//)

# payload
NOW=$(date +%s)
DATA=$(jq --argjson iat "$NOW" \
--argjson exp "$((NOW+DURATION))" \
--arg uuid "$(cat /proc/sys/kernel/random/uuid)" \
'. +{iat:$iat,auth_time:$iat,exp:$exp,jti:$uuid}' \
"$CLAIMS_FILE")
payload=$(echo "$DATA" | tr -d '\r\n' | base64 | tr -d '\r\n' | sed s/\+/-/g |sed 's/\//_/g' |  sed -E s/=+$//)

# sign w rsa private key
signature=$(echo "${jwt_header}.${payload}" | tr -d '\r\n' | openssl dgst -sha256 -binary -sign "$PRIVATE_KEY"  | openssl enc -base64 -A | tr -d '\n=' | tr -- '+/' '-_')

# assemble token
echo "${jwt_header}.${payload}.${signature}" | tr -d '\r\n'
