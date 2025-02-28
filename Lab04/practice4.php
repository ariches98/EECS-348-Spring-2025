<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Multiplication Table</title>
</head>
<body>
    <h1>Generate a Multiplication Table</h1>
    <form method="POST">
        <label>Enter a number: <input type="number" name="num" min="1"></label>
        <button type="submit">Generate</button>
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $num = intval($_POST["num"]);
        
        echo "<h2>Multiplication Table for $num</h2>";
        echo "<table border='1' cellpadding='5'>";

        // Table header
        echo "<tr><th>*</th>";
        for ($i = 1; $i <= $num; $i++) {
            echo "<th>$i</th>";
        }
        echo "</tr>";

        // Table rows
        for ($i = 1; $i <= $num; $i++) {
            echo "<tr><th>$i</th>";
            for ($j = 1; $j <= $num; $j++) {
                echo "<td>" . ($i * $j) . "</td>";
            }
            echo "</tr>";
        }

        echo "</table>";
    }
    ?>
</body>
</html>
