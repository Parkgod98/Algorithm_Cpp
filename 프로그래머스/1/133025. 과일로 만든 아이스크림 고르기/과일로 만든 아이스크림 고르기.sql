select f.flavor from first_half f
join ICECREAM_INFO i
on f.flavor = i.flavor
where f.TOTAL_ORDER > 3000
and
i.INGREDIENT_TYPE = 'fruit_based'
order by f.total_order Desc