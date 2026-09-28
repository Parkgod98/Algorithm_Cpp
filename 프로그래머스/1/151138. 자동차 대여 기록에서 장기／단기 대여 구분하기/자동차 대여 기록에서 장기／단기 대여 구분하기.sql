SELECT HISTORY_ID,
CAR_ID,
START_DATE,
END_DATE,
CASE 
WHEN datediff(end_date,START_DATE) >= 29
then "장기 대여"
ELSE "단기 대여" 
END
AS RENT_TYPE
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY WHERE start_date like '2022-09%'
order by history_id desc