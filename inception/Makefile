all: up

up: create_volumes
	@if [ -f srcs/.env ]; then \
		sudo echo "Up!"; \
		docker network create inception-network 2>/dev/null || true; \
		cd srcs && docker-compose up --build -d; \
		cd .. && sudo bash ./srcs/requirements/tools/hosts.sh add; \
	else \
		printf "Can't find the env file!"; \
	fi

down:
	@echo "Down!";
	@cd srcs && docker-compose down
	@sudo bash ./srcs/requirements/tools/hosts.sh delete;

create_volumes:
	@sudo mkdir -p /home/${USER}/data/wordpress-volume
	@sudo mkdir -p /home/${USER}/data/mariadb-volume
    
delete_volumes:
	@sudo rm -rf /home/${USER}/data/wordpress-volume
	@sudo rm -rf /home/${USER}/data/mariadb-volume

clean: delete_volumes
	@echo "Cleaning files..."
	@cd srcs && docker-compose down
	@sudo bash ./srcs/requirements/tools/hosts.sh delete
	@docker network prune
	@docker volume rm $$(docker volume ls -qf "dangling="true"") || true

fclean: delete_volumes clean
	@echo "FCleaning files..."
	@cd srcs && docker system prune -a --volumes
