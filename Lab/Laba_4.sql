
DROP TABLE IF EXISTS task_assignments;
DROP TABLE IF EXISTS tasks;
DROP TABLE IF EXISTS users;

CREATE TABLE tasks (
    id SERIAL PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    priority VARCHAR(20) CHECK (priority IN ('High', 'Medium', 'Low')),
    due_date DATE,
    status VARCHAR(20) CHECK (status IN ('Completed', 'In Progress', 'Deferred'))
);

CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);

CREATE TABLE task_assignments (
    assignment_id SERIAL PRIMARY KEY,
    task_id INT REFERENCES tasks(id) ON DELETE CASCADE,
    user_id INT REFERENCES users(id) ON DELETE CASCADE,
    assigned_date DATE DEFAULT CURRENT_DATE
);

CREATE INDEX idx_tasks_due_date ON tasks(due_date);
CREATE INDEX idx_tasks_status ON tasks(status);
CREATE INDEX idx_assignments_date ON task_assignments(assigned_date);
