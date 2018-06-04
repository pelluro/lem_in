CREATE TABLE `ft_table` (
    `id`                  INT AUTO_INCREMENT primary key NOT NULL,
    `login`               VARCHAR(8) DEFAULT 'toto' NOT NULL,
    `groupe`              ENUM('staff', 'student', 'other') NOT NULL,
    `date_de_creation`    DATE NOT NULL
);