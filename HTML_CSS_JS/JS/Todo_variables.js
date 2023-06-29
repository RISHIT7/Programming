let todo1 = "Get groceries";
let todo2 = "Wash Car";
let todo3 = "Make Dinnner";
let tile = "ToDo";
let text = "Click Me";

function addToDo(todoTitle) {
  let button = document.createElement("button");
  button.innerText = todoTitle;
  document.body.appendChild(button);
}

addToDo(todo1)
addToDo(todo2)
addToDo(todo3)

let title = document.createElement("title");
title.innerText = tile;
document.head.appendChild(title);
