show:
		cat Makefile
win:
		docker-compose -f ./docker/compose-win.yml up -d
mac:
		docker-compose -f ./docker/compose-mac.yml up -d