SELECT titre, resum
FROM film WHERE lower(resum)
LIKE lower('%vincent%')
ORDER BY id_film ASC;