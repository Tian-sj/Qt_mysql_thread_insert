drop database if exists test;
create database test;
use test;

CREATE TABLE `person` (
  `id` bigint NOT NULL AUTO_INCREMENT,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `phone` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `salary` float NOT NULL,
  `company` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `if_single` tinyint NOT NULL,
  `sex` tinyint NOT NULL,
  `address` varchar(225) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `create_time` datetime NOT NULL,
  `create_user` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=30170001 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
