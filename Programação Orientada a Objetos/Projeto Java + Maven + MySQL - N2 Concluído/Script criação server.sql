-- Script de criação do server Bankproject

-- Server port 3306 (default)

-- Script de criação do usuário a ser utilizado pelo app
-- Deve ser criado no Phpmyadmin
-- Login: rootapp
-- Senha: 1234

CREATE SCHEMA IF NOT EXISTS dbBankProject DEFAULT CHARACTER SET utf8; 

CREATE TABLE IF NOT EXISTS dbBankProject.tb_usuario (
  id INT(11) NOT NULL AUTO_INCREMENT,
  nome VARCHAR(50) NOT NULL,
  login VARCHAR(50) NOT NULL,
  senha VARCHAR(50) NOT NULL,
  saldo FLOAT NULL DEFAULT NULL,
  pix VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (id))
ENGINE = InnoDB
AUTO_INCREMENT = 11
DEFAULT CHARACTER SET = utf8;



