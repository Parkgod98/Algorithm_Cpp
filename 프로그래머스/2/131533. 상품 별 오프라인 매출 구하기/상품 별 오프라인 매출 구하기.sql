SELECT p.product_code as PRODUCT_CODE, SUM((p.PRICE)*(o.sales_amount)) AS SALES FROM PRODUCT p JOIN offline_sale o
ON p.product_id = o.product_id
GROUP by p.product_code
order by SALES DESC, p.product_code asc