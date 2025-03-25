const schema = {
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "products": {
            "type": "array",
            "items": {
                "type": "object",
                "properties": {
                    "productName": {
                        "type": "string"
                    },
                    "productCode": {
                        "type": "string"
                    },
                    "price": {
                        "type": "number",
                        "minimum": 0
                    },
                    "quantity": {
                        "type": "integer",
                        "minimum": 0
                    }
                },
                "required": ["productName", "productCode", "price", "quantity"]
            }
        }
    },
    "required": ["products"]
};

function validateJSON() {
    const jsonInput = document.getElementById('jsonInput').value;
    const resultDiv = document.getElementById('result');
    const ajv = new Ajv();
    const validate = ajv.compile(schema);

    try {
        const jsonData = JSON.parse(jsonInput);
        const valid = validate(jsonData);

        if (valid) {
            resultDiv.innerHTML = '<p class="valid">JSON is valid!</p>';
        } else {
            resultDiv.innerHTML = '<p class="invalid">JSON is invalid:</p><pre>' + JSON.stringify(validate.errors, null, 2) + '</pre>';
        }
    } catch (e) {
        resultDiv.innerHTML = '<p class="invalid">Invalid JSON format:</p><pre>' + e.message + '</pre>';
    }
}