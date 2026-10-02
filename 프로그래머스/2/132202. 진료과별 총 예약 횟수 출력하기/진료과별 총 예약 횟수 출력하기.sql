SELECT MCDP_CD AS 진료과코드, COUNT(*) AS '5월예약건수' FROM appointment where apnt_ymd LIKE '%2022-05%' GROUP by mcdp_cd order by 5월예약건수 ASC, MCDP_CD ASC
