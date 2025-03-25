
function onLogin() { 
  var userName = document.getElementById("userName").value;
  var password = document.getElementById("password").value;
  if (userName === "admin" && password === "123456") {
    alert("Login success!\nRedirect to next page...");
    return true;
  } else {
    alert("Login failed!\nIncorrect username or password...");
    return false;
  }
}
function onAddClass() {
  let newClassName = prompt("Input new class name:", "C2307l");
  if (newClassName !== "") {
    var cbClass = document.getElementById("cbClass");
    var option = document.createElement("option");
    option.value = newClassName;
    option.text = newClassName;
    cbClass.appendChild(option);

    alert("New class added successfully!");
  }
}

function onAddStudent() {
  var data = readFormData();
  insertNewRecord(data);
  resetForm();
  return false;
}
function readFormData() {
  var formData = {};
  formData.studentName = document.getElementById("studentName").value;
  formData.studentDOB = document.getElementById("studentDOB").value;
  var gens = document.getElementsByName("rbGender");
  for (var gen of gens) {
    if (gen.checked) 
      formData.studentGender = gen.value;
  }
  var studentLanguages = [];
  var languages = document.getElementsByName("ckbLanguage"); 
  for (var language of languages) {
    if (language.checked) 
      studentLanguages.push(language.value);
  }
  formData.studentLanguage = studentLanguages.join(", ");
  formData.studentClass = document.getElementById("cbClass").value;

  return formData;
}
function resetForm() {
  document.getElementById("studentName").value = "";
  document.getElementById("studentDOB").value = "";
  document.getElementById("rbMale").checked = true;
  document.getElementById("ckbEnglish").checked = true;
  document.getElementById("ckbVietnamese").checked = true;
  document.getElementById("ckbJapanese").checked = false;
  document.getElementById("ckbChinese").checked = false;
  document.getElementById("ckbFrench").checked = false;
  var table = document.getElementById("tableStudent");
  var divTotal = document.getElementById("total");
  divTotal.innerHTML = "<b>Total: </b> " + (table.rows.length - 1);
}

function insertNewRecord(data) {
  var table = document.getElementById("tableStudent")
                      .getElementsByTagName("tbody")[0];
  table.appendChild(createRow(data));
}

function createRow(data){
  var x = document.getElementById("Id");
  var y = document.getElementsByClassName("className");
  var z = document.getElementsByName("name");
  var k = document.getElementsByTagName("tagname");
   

  var row = document.createElement("tr");
  row.appendChild(createCell(data.studentName));
  row.appendChild(createCell(data.studentClass));
  row.appendChild(createCell(data.studentDOB));
  row.appendChild(createCell(data.studentGender));
  row.appendChild(createCell(data.studentLanguage));

  var cellDelete = document.createElement("td");
  var btDelete = document.createElement("a");
  btDelete.href = "#";
  btDelete.innerText = "Delete";
  btDelete.onclick = function (){
    if (confirm("Are you sure to delete?")) {
      debugger;
      row.remove();
      resetForm();
    }
  }
  cellDelete.appendChild(btDelete);
  row.appendChild(cellDelete);
  return row;
}
function createCell(textData){
  var cell = document.createElement("td");
  cell.innerText = textData;
  return cell;
}
function onDelete(element) {
  if (confirm("Are you sure to delete?")) {
    debugger;
    row = element.parentElement.parentElement;
    document.getElementById("tableStudent").deleteRow(row.rowIndex);
    alert("Data deleted successfully!");
    resetForm();
  }
}
