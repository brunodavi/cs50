SELECT
  title,
  year
FROM
  movies
WHERE
  LOWER(title) LIKE 'Harry Potter%'
ORDER BY
  year;
