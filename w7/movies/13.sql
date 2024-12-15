SELECT DISTINCT
  people.name
FROM
(
  SELECT
    people.id AS id,
    movies.id AS movie_id
  FROM
    movies
  JOIN
    stars ON stars.movie_id = movies.id
  JOIN
    people ON stars.person_id = people.id
  WHERE
    people.name = 'Kevin Bacon'
    AND people.birth = 1958
) AS kevin
JOIN
  stars ON stars.movie_id = kevin.movie_id
JOIN
  people ON stars.person_id = people.id
WHERE
  people.id != kevin.id;
