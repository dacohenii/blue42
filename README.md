### Cloning

This repository contains submodules (which themselves contain submodules). Use the follwoing command to clone this repo:

    git clone git@github.com:lagerdata/blue42.git --recurse-submodules

If you've already cloned the repo, run this command to pull submodules:

    git submodule update --init --recursive


### Building

#### Cmake
	docker pull lagerdata/cortexm-devenv  
	
	docker run --name [LABEL] -v /path/to/this/folder:/app --rm lagerdata/cortexm-devenv /bin/bash -c "mkdir -p _build;cd _build; cmake .. -G Ninja -DCMAKE_TOOLCHAIN_FILE=../cmake/arm-gcc-toolchain.cmake"  

	docker run --name [LABEL] -v /path/to/this/folder:/app --rm lagerdata/cortexm-devenv /bin/bash -c "cd _build ; cmake --build ."



### Install docker in vm (one time)
    https://linuxize.com/post/how-to-install-and-use-docker-on-debian-10/

### Build image (one time)
    docker build .

### Get image ID
    docker images

### Initial setup (one time; running in vm, use image id from above step)
    docker run -it --name blue42 -v /vagrant/projects/blue42/:/app --rm IMAGE_ID /bin/bash -c "mkdir -p _build; cd _build ; cmake .. -G Ninja -DCMAKE_TOOLCHAIN_FILE=../cmake/arm-gcc-toolchain.cmake"

### Compile (running in vm)
    docker run -it --name blue42 -v /vagrant/projects/blue42/:/app --rm IMAGE_ID /bin/bash -c "cd _build ; cmake --build ."
