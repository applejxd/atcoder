show:
		cat Makefile
compose:
		docker-compose -f ./docker/compose.yml up -d
mac:
		docker-compose -f ./docker/compose-mac.yml up -d