#!/bin/sh
# read web server input and respond accordingly.
DEFAULT_CLAIMS_FILE="/claims/example_claim.json"

while read -r str; do
  str=$(echo "$str" | tr -d '\r\n')
  if echo "$str" | grep -qE '^GET /'; then
    request=$(echo "$str" | cut -d' ' -f2)
    request_file=$(echo "$request" | cut -d'?' -f1)
    request_duration=$(echo "$request" | grep '?' | cut -d'=' -f2)
  elif [ -z "$str" ]; then
    if [ "$request_file" = '/' ]; then
      filename="$DEFAULT_CLAIMS_FILE"
    else
      filename="/claims$request_file"
    fi
    if [ -z "$request_duration" ]; then
      request_duration="$DURATION"
    fi
    if [ -e "$filename" ]; then
      result=$(/sign_jwt_rsa.sh "$filename" "$request_duration")
      length=${#result}
      length=$((length+1))
      echo -e "HTTP/1.1 200 OK\nContent-Length: $length\n\n$result"
    else
      result="not found"
      length=${#result}
      length=$((length+1))
      echo -e "HTTP/1.1 404 Not Found\nContent-Length:$length\n\n$result"
    fi
  fi
done
