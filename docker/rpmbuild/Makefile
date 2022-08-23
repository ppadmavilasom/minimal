IMAGE_NAME=builder
CONTAINER_NAME=builder
BUILD_DIR=/usr/src/photon

build: clean build_docker
	docker run --rm -it --name $(CONTAINER_NAME) \
-v$(CURDIR)/SPECS:$(BUILD_DIR)/SPECS \
-v$(CURDIR)/SOURCES:$(BUILD_DIR)/SOURCES \
-v$(CURDIR)/RPMS:$(BUILD_DIR)/RPMS \
$(IMAGE_NAME) rpmbuild -ba -D 'debug_package %{nil}' $(BUILD_DIR)/SPECS/bc.spec

build_docker:
	docker build -t $(IMAGE_NAME) .

clean:
	-docker stop $(CONTAINER_NAME) && docker rm $(CONTAINER_NAME)

.PHONY: build build_docker clean
