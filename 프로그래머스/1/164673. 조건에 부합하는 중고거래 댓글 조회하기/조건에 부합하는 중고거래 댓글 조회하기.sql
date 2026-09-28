select b.title, b.board_id, r.REPLY_ID, r.WRITER_ID, r.contents, r.created_date from USED_GOODS_BOARD b
join USED_GOODS_REPLY r
on b.board_id = r.board_id
where b.created_date like '2022-10%'
order by r.created_date asc, b.title asc