select i.item_id AS ITEM_ID, i.ITEM_NAME AS ITEM_NAME FROM ITEM_TREE t
JOIN ITEM_INFO i
ON t.item_id = i.item_id
WHERE t.parent_item_id IS NULL