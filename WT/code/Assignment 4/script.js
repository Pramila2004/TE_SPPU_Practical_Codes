let display = document.getElementById("display");

// Append numbers to input field
function appendNumber(num) {
    display.value += num;
}

// Append operators (+, -, *, /, .)
function appendOperator(operator) {
    let lastChar = display.value.slice(-1);
    if (["+", "-", "*", "/", "."].includes(lastChar)) {
        alert("Invalid Operator Placement!");
        return;
    }
    display.value += operator;
}

// Clear the display
function clearDisplay() {
    display.value = "";
}

// Perform calculation
function calculateResult() {
    try {
        display.value = eval(display.value);
    } catch {
        alert("Invalid Expression!");
        clearDisplay();
    }
}

// Square of number
function squareNumber() {
    let value = display.value;
    if (isNaN(value) || value === "") {
        alert("Enter a valid number first!");
        return;
    }
    display.value = Math.pow(parseFloat(value), 2);
}

// Prompt user for number input
function promptNumber() {
    let input = prompt("Enter a number:");
    if (input === null || input.trim() === "") {
        alert("Input is empty!");
        return;
    }
    if (isNaN(input)) {
        alert("Invalid Number!");
        return;
    }
    display.value = input;
}
