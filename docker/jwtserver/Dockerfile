FROM alpine:3.12.0
RUN apk add openssl jq
COPY start.sh /
COPY process_request.sh /
COPY sign_jwt_rsa.sh /
COPY claims /claims
ENV PORT 9090
ENV DURATION 600
ENTRYPOINT ["/start.sh"]
