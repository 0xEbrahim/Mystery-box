SELECT p1.name as Customers 
FROM Customers p1 LEFT JOIN Orders p2
ON p1.id=p2.customerId WHERE p2.customerId IS NULL;
