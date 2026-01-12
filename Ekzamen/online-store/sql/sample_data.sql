-- Clear existing data (optional)
-- DELETE FROM order_items;
-- DELETE FROM orders;
-- DELETE FROM products;
-- DELETE FROM users;
-- DELETE FROM audit_log;

-- Insert test users
INSERT INTO users (name, email, role, password_hash) VALUES
('Admin User', 'admin@store.com', 'admin', 'admin123'),
('Manager User', 'manager@store.com', 'manager', 'manager123'),
('Customer One', 'customer1@store.com', 'customer', 'customer123'),
('Customer Two', 'customer2@store.com', 'customer', 'customer123');

-- Insert test products
INSERT INTO products (name, price, stock_quantity) VALUES
('Laptop', 99999.99, 10),
('Smartphone', 49999.99, 25),
('Headphones', 9999.99, 50),
('Keyboard', 2999.99, 100),
('Mouse', 1999.99, 75);

-- Insert test orders
INSERT INTO orders (user_id, status, total_price) VALUES
(3, 'completed', 109999.98),
(3, 'pending', 2999.99),
(4, 'processing', 5999.98);

-- Insert order items
INSERT INTO order_items (order_id, product_id, quantity, price) VALUES
(1, 1, 1, 99999.99),
(1, 3, 1, 9999.99),
(2, 4, 1, 2999.99),
(3, 5, 2, 1999.99),
(3, 3, 1, 9999.99);

-- Update product stock
UPDATE products 
SET stock_quantity = stock_quantity - 1 
WHERE product_id IN (1, 3, 4);

UPDATE products 
SET stock_quantity = stock_quantity - 2 
WHERE product_id = 5;

-- Add some audit logs
INSERT INTO audit_log (entity_type, entity_id, operation, performed_by) VALUES
('order', 1, 'insert', 3),
('order', 2, 'insert', 3),
('order', 3, 'insert', 4),
('product', 1, 'insert', 1),
('product', 2, 'insert', 1);

SELECT 'Test data inserted successfully' AS message;
