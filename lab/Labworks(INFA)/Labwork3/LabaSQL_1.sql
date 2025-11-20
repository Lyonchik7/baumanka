
-- Удаляем таблицы если они существуют (в правильном порядке из-за внешних ключей)
DROP TABLE IF EXISTS task_assignments;
DROP TABLE IF EXISTS tasks;
DROP TABLE IF EXISTS users;


-- ПУНКТЫ 2 И 3
CREATE TABLE users (
	id INT PRIMARY KEY,
	name VARCHAR(100)
);

CREATE TABLE tasks (
    id INT PRIMARY KEY,
    title VARCHAR(250),
    priority VARCHAR(20),
    due_date DATE,
    status VARCHAR(20)
);

CREATE TABLE task_assignments (
    assignment_id INT PRIMARY KEY,
    task_id INT,
    user_id INT,
	FOREIGN KEY (task_id) REFERENCES tasks(id),
	FOREIGN KEY (user_id) REFERENCES users(id)
);

-- ПУНКТ 4
-- Заполнение таблицы users данными о пользователях
INSERT INTO users (id, name) VALUES
(1, 'Иван Петров'),
(2, 'Мария Сидорова'),
(3, 'Алексей Козлов'),
(4, 'Елена Новикова'),
(5, 'Дмитрий Волков');

-- Заполнение таблицы tasks данными о задачах (новые названия)
INSERT INTO tasks (id, title, priority, due_date, status) VALUES
(1, 'Создать мобильное приложение', 'Высокий', '2024-02-15', 'В процессе'),
(2, 'Написать техническую документацию', 'Средний', '2024-02-28', 'Новая'),
(3, 'Починить ошибку входа в систему', 'Высокий', '2024-02-10', 'В процессе'),
(4, 'Протестировать новый функционал', 'Средний', '2024-02-20', 'Отложена'),
(5, 'Подготовить презентацию для клиента', 'Низкий', '2024-03-01', 'Новая'),
(6, 'Ускорить загрузку сайта', 'Высокий', '2024-02-12', 'В процессе');

-- Заполнение таблицы task_assignments данными о назначениях
INSERT INTO task_assignments (assignment_id, task_id, user_id) VALUES
(1, 1, 1),
(2, 1, 2),
(3, 2, 3),
(4, 3, 1),
(5, 3, 4),
(6, 4, 2),
(7, 5, 5),
(8, 6, 1),
(9, 6, 3),
(10, 6, 5);

-- ПУНКТ 5
SELECT *
FROM tasks
ORDER BY priority, due_date;

SELECT t.*
FROM tasks t, task_assignments ta, users u
WHERE t.id = ta.task_id 
  AND ta.user_id = u.id 
  AND u.name = 'Иван Петров';

SELECT *
FROM tasks
WHERE priority = 'Высокий'
  AND due_date BETWEEN CURRENT_DATE AND CURRENT_DATE + 7;

SELECT status, COUNT(*)
FROM tasks
GROUP BY status;

-- ПУНКТ 6 

-- 1. Просроченные задачи и ответственные пользователи
SELECT 
    t.title as задача,
    t.due_date as срок,
    u.name as пользователь
FROM tasks t
JOIN task_assignments ta ON t.id = ta.task_id
JOIN users u ON ta.user_id = u.id
WHERE t.due_date < CURRENT_DATE 
  AND t.status != 'Выполнена';

-- 2. Обновление статуса задачи
UPDATE tasks 
SET status = 'Выполнена' 
WHERE id = 2;

-- 3. Удаление задачи 
-- Удаляем назначения задачи
DELETE FROM task_assignments WHERE task_id = 5;
-- Удаляем саму задачу
DELETE FROM tasks WHERE id = 5;
