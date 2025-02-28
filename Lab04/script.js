function verifyPassword() {
    let pass1 = document.getElementById("password1").value;
    let pass2 = document.getElementById("password2").value;
    let message = document.getElementById("message");

    if (pass1.length < 8) {
        message.style.color = "red";
        message.textContent = "Password must be at least 8 characters long.";
        return;
    }

    if (pass1 !== pass2) {
        message.style.color = "red";
        message.textContent = "Passwords do not match!";
        return;
    }

    message.style.color = "green";
    message.textContent = "Passwords match!";
}

function changeStyle() {
    let r = document.getElementById("red").value;
    let g = document.getElementById("green").value;
    let b = document.getElementById("blue").value;
    let borderWidth = document.getElementById("borderWidth").value;
    
    let text = document.getElementById("text");
    text.style.color = `rgb(${r}, ${g}, ${b})`;
    text.style.border = `${borderWidth}px solid rgb(${r}, ${g}, ${b})`;
}
