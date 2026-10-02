SELECT book_id, author_name, published_date FROM book b join Author a
ON b.author_id = a.author_id
where b.CATEGORY = '경제'
order by b.published_date asc