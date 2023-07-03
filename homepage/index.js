let week = 0;

document.getElementById("increase").onclick = () => {
  if (week >= 0 && week < 10){
    week += 1;
    document.getElementById("week-number").innerHTML = `Week ${week}`;
  }
}

document.getElementById("decrease").onclick = () => {
  if (week > 0 && week <= 10){
    week -= 1;
    document.getElementById("week-number").innerHTML =`Week ${week}`;
  }
}

document.getElementById("submit").onclick = () => {

  const pSet = week;

  switch (pSet) {
    case 0:
      document.getElementById("output").innerHTML = 'Week 0, Language - Scratch, Problem Set - Create a program in Scratch';
      break;
    case 1:
      document.getElementById("output").innerHTML = 'Week 1, Language - C, Problem Set - Mario / Scratch';
      break;
    case 2:
      document.getElementById("output").innerHTML = 'Week 2, Language - C, Problem Set - Caesar / Readability';
      break;
    case 3:
      document.getElementById("output").innerHTML = 'Week 3, Language - C, Problem Set - Plurality / Runoff';
      break;
    case 4:
      document.getElementById("output").innerHTML = 'Week 4, Language - C, Problem Set - Filter / Recover';
      break;
    case 5:
      document.getElementById("output").innerHTML = 'Week 5, Language - C, Problem Set - Speller';
      break;
    case 6:
      document.getElementById("output").innerHTML = 'Week 6, Language - Python, Problem Set - Sentimental / DNA';
      break;
    case 7:
      document.getElementById("output").innerHTML = 'Week 7, Language - SQL, Problem Set - Movies / Fiftyville';
      break;
    case 8:
      document.getElementById("output").innerHTML = 'Week 8, Language - HTML, CSS, Javascript, Problem Set - Homepage';
      break;
    case 9:
      document.getElementById("output").innerHTML = 'Week 9, Language - Flask, Problem Set - Finance';
      break;
    case 10:
      document.getElementById("output").innerHTML = "Week 10, Language - Any, Problem Set - Final Project (student's own project)";
      break;
    default:
      document.getElementById("output").innerHTML = 'error';
  }
}
