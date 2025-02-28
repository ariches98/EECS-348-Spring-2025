function changeStyle() {
    let r = document.getElementById("red").value;
    let g = document.getElementById("green").value;
    let b = document.getElementById("blue").value;
    let borderWidth = document.getElementById("borderWidth").value;

    let text = document.getElementById("text");
    text.style.color = `rgb(${r}, ${g}, ${b})`;
    text.style.border = `${borderWidth}px solid rgb(${r}, ${g}, ${b})`;
}
