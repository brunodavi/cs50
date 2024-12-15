SELECT DISTINCT
  people.name
FROM
  movies
JOIN
  stars ON stars.movie_id = movies.id
JOIN
  people ON stars.person_id = people.id
JOIN
  ratings ON ratings.movie_id = movies.id
WHERE
  rating = 9.0;
