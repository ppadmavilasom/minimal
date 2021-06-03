IMG_NAME=jwtserver
TEST_SERVER=jwtserver_test
PORT=9090

build:
	docker build -t $(IMG_NAME) .

stop:
	-docker stop $(TEST_SERVER)

test: stop build
	docker run --rm -itd \
	-p$(PORT):$(PORT) \
	--name $(TEST_SERVER) jwtserver
	
	curl -s localhost:$(PORT)/unknown | grep "not found"

privateKey.pem:
	openssl genrsa -out privateKey.pem 2048

# assumes a local private key
local_test: privateKey.pem test
	docker cp privateKey.pem $(TEST_SERVER):/privateKey.pem
	curl -s localhost:$(PORT)/example_claim.json

.PHONY: stop test local_test
