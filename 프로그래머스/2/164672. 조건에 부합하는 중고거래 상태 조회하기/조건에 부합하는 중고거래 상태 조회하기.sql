SELECT board_id, writer_id, title, price,
CASE
    WHEN STATUS = 'SALE' THEN '판매중'
    WHEN STATUS = 'RESERVED' THEN '예약중'
    WHEN STATUS = 'DONE' THEN '거래완료'
END
AS STATUS from USED_GOODS_BOARD
where created_date = '2022-10-05'
order by board_id DESC
