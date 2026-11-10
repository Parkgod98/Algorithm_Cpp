
select SUM(PRICE) as TOTAL_PRICE FROM item_info GROUP by rarity HAVING rarity = 'LEGEND'