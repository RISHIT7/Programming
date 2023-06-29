// Model
// if local strage has a todo array then uses it, or use default array
let todos;

// retrive from local storage and check if that is an array
const savedTodos = JSON.parse(localStorage.getItem('todos'));

if (Array.isArray(savedTodos)) {
  todos = savedTodos
} else {
  todos = [
    {
      Title: "Get groceries",
      DueDate: "10-04-2021",
      id: "id1",
    },
    {
      Title: "Wash Car",
      DueDate: "03-04-2021",
      id: "id2",
    },
    {
      Title: "Make dinner",
      DueDate: "03-04-2021",
      id: "id3",
    },
  ];
} 
// Creates a todo
function createTodo(title, dueDate) {
  const id = "" + new Date().getTime(); // Amazing! id generator
  todos.push({
    Title: title,
    DueDate: dueDate,
    id: id,
  });
  setTodos();
}
// Deletes a todo
function removeTodo(idToDelete) {
  todos = todos.filter(function (todo) {
    // if the id of this todo matches the id of idToDelete, return false
    // for everything elses return true
    if (todo.id === idToDelete) {
      return false;
    } else {
      return true;
    }
  });
  setTodos();
}

// View Section
function render() {
  document.getElementById("div-display").innerHTML = "";

  todos.forEach(function (todo) {
    const element = document.createElement("div");
    element.innerText = todo.Title + " " + todo.DueDate;

    const deleteButton = document.createElement("button");
    deleteButton.innerText = "Delete";
    deleteButton.style = "margin-left: 12px; ";
    deleteButton.onclick = deleteTodo;
    deleteButton.id = todo.id;
    element.appendChild(deleteButton);

    const todoList = document.getElementById("div-display");
    todoList.appendChild(element);
  });
}

render();
function setTodos(){
  localStorage.setItem('todos', JSON.stringify(todos));
}
// Controller
function Add() {
  const textbox = document.getElementById("input-name");
  const title = textbox.value;
  const datePicker = document.getElementById("input-date");
  const dueDate = datePicker.value;
  createTodo(title, dueDate);
  render();
}

function deleteTodo(event) {
  //target property!
  const deleteButton = event.target;
  const idToDelete = deleteButton.id;
  removeTodo(idToDelete);
  render();
}