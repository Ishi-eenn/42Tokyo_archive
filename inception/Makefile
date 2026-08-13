SHELL = bash

COMPOSE_FILE = docker-compose.yml
DATA_DIR = /home/$(USER)/data

all: up

build:
	docker compose -f $(COMPOSE_FILE) build

up:
	@mkdir -p $(DATA_DIR)/database
	@mkdir -p $(DATA_DIR)/web
	docker compose -f $(COMPOSE_FILE) up -d --build

down:
	docker compose -f $(COMPOSE_FILE) down

clean:
	docker compose -f $(COMPOSE_FILE) down --volumes

.PHONY: all build up down clean
