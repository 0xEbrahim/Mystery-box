SELECT customer_number
FROM (
    SELECT COUNT(order_number) AS order_count, customer_number
    FROM Orders
    GROUP BY customer_number
) AS tb
WHERE tb.order_count = (
    SELECT MAX(order_count)
    FROM (
        SELECT COUNT(order_number) AS order_count
        FROM Orders
        GROUP BY customer_number
    ) AS inner_tb
);
