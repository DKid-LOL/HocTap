document.addEventListener("DOMContentLoaded", function() {

    function loadXMLDoc(filename) {
        return new Promise((resolve, reject) => {
            const xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    resolve(this.responseXML);
                }
            };
            xhttp.open("GET", filename, true);
            xhttp.send();
        });
    }

    function displayBooks(xml) {
        const books = xml.getElementsByTagName("Book");
        let output = "<ul>";
        for (let i = 1; i < books.length; i++) {
            const id = books[i].getElementsByTagName("ID")[0].childNodes[0].nodeValue;
            const title = books[i].getElementsByTagName("Title")[0].childNodes[0].nodeValue;
            const author = books[i].getElementsByTagName("Author")[0].childNodes[0].nodeValue;
            const year = books[i].getElementsByTagName("PublicationYear")[0].childNodes[0].nodeValue;
            const category = books[i].getElementsByTagName("Category")[0].childNodes[0].nodeValue;
            output += `<li><strong>${title}</strong> by ${author} (${year}) - Category: ${category}</li>`;
        }
        output += "</ul>";
        document.getElementById("bookList").innerHTML = output;
    }

    // Load and display the books
    loadXMLDoc("book.xml").then(displayBooks).catch(error => console.error(error));
});