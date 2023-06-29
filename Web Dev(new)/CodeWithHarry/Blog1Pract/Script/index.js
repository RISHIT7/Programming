document.querySelector(".menu-cross").style.display = "none";
document.querySelector(".hamburger").addEventListener("click", () => {
  document.querySelector(".sidebar").classList.toggle("sidebarGo");
  if (document.querySelector(".sidebar").classList.contains("sidebarGo")) {
    document.querySelector(".menu-cross").style.display = "none";
    setTimeout(() => {
      document.querySelector(".menu-ham").style.display = "inline";
    }, 350);
  } else {
    document.querySelector(".menu-ham").style.display = "none";
    setTimeout(() => {
      document.querySelector(".menu-cross").style.display = "inline";
    }, 350);
  }
});
