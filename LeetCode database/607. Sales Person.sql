SELECT s.name 
FROM salesperson s 
WHERE s.name not in 
(
    SELECT s.name 
    from salesperson s 
    RIGHT JOIN Orders o 
    ON s.sales_id=o.sales_id 
    LEFT JOIN Company c 
    ON c.com_id=o.com_id
WHERE c.name='Red'
)
