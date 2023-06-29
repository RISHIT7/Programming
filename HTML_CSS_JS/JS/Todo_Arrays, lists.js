todos = ["Car Wash", "Dish Wash", "Brain Wash"];

todos.forEach(function (todoTitle) {
  element = document.createElement("div");
  element.innerText = todos;
  document.body.appendChild(element);
});

function addTodo(todoTitle) {
  let element = document.createElement("div");
  element.innerText = todos;
  document.body.appendChild(element);
}
