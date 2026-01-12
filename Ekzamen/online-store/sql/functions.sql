-- Simple function to get order status
CREATE OR REPLACE FUNCTION get_order_status(order_id_param INTEGER)
RETURNS VARCHAR AS $$
BEGIN
    RETURN (SELECT status FROM orders WHERE order_id = order_id_param);
END;
$$ LANGUAGE plpgsql;

-- Function to count user orders
CREATE OR REPLACE FUNCTION count_user_orders(user_id_param INTEGER)
RETURNS INTEGER AS $$
BEGIN
    RETURN (SELECT COUNT(*) FROM orders WHERE user_id = user_id_param);
END;
$$ LANGUAGE plpgsql;

-- Function to check if order can be returned
CREATE OR REPLACE FUNCTION can_return_order(order_id_param INTEGER)
RETURNS BOOLEAN AS $$
DECLARE
    order_status VARCHAR;
    order_date TIMESTAMP;
BEGIN
    SELECT status, order_date 
    INTO order_status, order_date
    FROM orders 
    WHERE order_id = order_id_param;
    
    RETURN order_status = 'completed' 
           AND order_date > CURRENT_DATE - INTERVAL '30 days';
END;
$$ LANGUAGE plpgsql;
