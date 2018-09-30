<?php

header("Content-Type: text/html; charset=UTF-8");
$con = mysqli_connect("localhost", "qkddmswl1234", "Tjdnfrhdah", "qkddmswl1234");

$user_id = $_POST["user_id"];

$result=mysqli_query($con, "DELETE FROM favor_line WHERE user_id='$user_id'");

$response = array();
$response["success"] = true;

echo json_encode($response);

 ?>
