SELECT u.USER_ID, u.NICKNAME, SUM(b.PRICE) AS TOTAL_SALES from used_goods_board b
JOIN used_goods_user u
ON b.writer_id = u.user_id
WHERE b.status = 'DONE'
GROUP BY u.user_id, u.nickname
HAVING SUM(b.PRICE) >= 700000
ORDER BY TOTAL_SALES ASC