-- 코드를 작성해주세요

select SUM(PRICE) as TOTAL_PRICE FROM item_info GROUP by rarity HAVING rarity = 'LEGEND'