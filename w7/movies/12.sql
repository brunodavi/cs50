SELECT
  movies.title
FROM
  movies
JOIN
  stars ON stars.movie_id = movies.id
JOIN
  people ON stars.person_id = people.id
WHERE
  people.name = 'Bradley Cooper'
  OR people.name = 'Jennifer Lawrence'
GROUP BY
  movies.title
HAVING
  COUNT(movies.title) = 2;
