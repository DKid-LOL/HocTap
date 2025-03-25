// Hàm cập nhập sau khi thay đổi giá trị trong bảng
function updateStudentCount() {
    const studentCount = document.getElementById("studentList").getElementsByTagName("tr").length; // Trừ 1 để loại bỏ hàng tiêu đề
    const studentCountElement = document.getElementById("studentCount");
    studentCountElement.textContent = `Total Students: ${studentCount}`;
}

function deleteStudent(row) {
// Xác định hàng (tr) của nút "Delete" được nhấn
const parentRow = row.parentNode.parentNode;

// Loại bỏ hàng khỏi tbody
parentRow.parentNode.removeChild(parentRow);
updateStudentCount();
}
function addStudent() {
let name = document.getElementById("name").value;
let dob = document.getElementById("dob").value;
let studentList = document.getElementById("studentList"); 
let genderMale = document.getElementById("male").checked;
let genderFemale = document.getElementById("female").checked;
let grade = document.getElementById("class").value;
// const langeng = document.getElementById("eng").checked;
// const langvi = document.getElementById("vi").checked;
// const langjp = document.getElementById("jp").checked;
// const langcn = document.getElementById("cn").checked;
// const langfr = document.getElementById("fr").checked;
// const lang = langeng ? "English" : (langvi ? "Vietnamese" : (langjp ? "Japanese" : (langcn ? "Chinese" : (langfr ? "French" : "unknow"))));
let selectedLanguages = document.querySelectorAll('input[type="checkbox"]:checked');

// Chuyển các giá trị của checkbox đã chọn thành một mảng
let selectedLanguageValues = Array.from(selectedLanguages).map(language => language.value);

let gender = genderMale ? "Nam" : (genderFemale ? "Nữ" : "Không xác định");

// // Hiển thị các giá trị của checkbox đã chọn trong ô "Language" của bảng
// const languageCell = document.getElementById("selectedLanguages");
// languageCell.textContent = selectedLanguageValues.join(", ");


// Tạo một hàng mới trong bảng
const row = document.createElement("tr");
row.innerHTML = `
<td>${name}</td>
<td>${grade}</td>
<td>${dob}</td>
<td>${gender}</td>
<td id="selectedLanguages">${selectedLanguageValues.join(", ")}</td>
<td><a href="#" onclick="deleteStudent(this)">Delete</a></td>
`;


// Thêm hàng mới vào bảng
studentList.appendChild(row);

updateStudentCount();
// Xóa dữ liệu đã nhập trong form
document.getElementById("name").value = "";
document.getElementById("dob").value = "";
document.getElementById("class").value = "";
document.getElementById("male").checked = false;
document.getElementById("female").checked = false;
// document.getElementById("eng").checked = false;
// document.getElementById("vi").checked = false;
// document.getElementById("jp").checked = false;
// document.getElementById("cn").checked = false;
// document.getElementById("fr").checked = false;
selectedLanguages.forEach(language => language.checked = false);
// document.getElementById("female").checked = false;
// document.getElementById("female").checked = false;

}