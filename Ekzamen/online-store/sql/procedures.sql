-- Procedure to create order
CREATE OR REPLACE PROCEDURE create_new_order(
    user_id_param INTEGER,
    OUT new_order_id INTEGER,
    OUT result_message VARCHAR
)
LANGUAGE plpgsql
AS $$
BEGIN
    INSERT INTO orders (user_id) 
    VALUES (user_id_param)
    RETURNING order_id INTO new_order_id;
    
    result_message := 'Order created successfully';
    
    -- Log to audit
    INSERT INTO audit_log (entity_type, entity_id, operation, performed_by)
    VALUES ('order', new_order_id, 'insert', user_id_param);
    
    COMMIT;
EXCEPTION
    WHEN OTHERS THEN
        ROLLBACK;
        result_message := 'Error: ' || SQLERRM;
END;
$$;

-- Procedure to update order status
CREATE OR REPLACE PROCEDURE update_order_status(
    order_id_param INTEGER,
    new_status VARCHAR,
    user_id_param INTEGER
)
LANGUAGE plpgsql
AS $$
DECLARE
    old_status VARCHAR;
BEGIN
    -- Get current status
    SELECT status INTO old_status 
    FROM orders 
    WHERE order_id = order_id_param;
    
    -- Update status
    UPDATE orders 
    SET status = new_status 
    WHERE order_id = order_id_param;
    
    -- Log to audit
    INSERT INTO audit_log (entity_type, entity_id, operation, performed_by)
    VALUES ('order', order_id_param, 'update', user_id_param);
    
    COMMIT;
EXCEPTION
    WHEN OTHERS THEN
        ROLLBACK;
END;
$$;
