var app = angular.module("myApp", []);

app.controller("registerCtrl", function ($scope) {
  $scope.registerUser = function () {
    var user = {
      firstName: $scope.firstName,
      lastName: $scope.lastName,
      username: $scope.username,
      password: $scope.password
    };

    localStorage.setItem($scope.username, JSON.stringify(user));

    $scope.firstName = "";
    $scope.lastName = "";
    $scope.username = "";
    $scope.password = "";

    $scope.successMessage = "Registration successful!";
  };
});

app.controller("loginCtrl", function ($scope) {
  $scope.loginUser = function () {
    var user = JSON.parse(localStorage.getItem($scope.username));
    if (user && user.password === $scope.password) {
      localStorage.setItem("loggedInUser", user.firstName + " " + user.lastName);
      window.location.href = "home.html"; // Redirect to home page
    } else {
      $scope.errorMessage = "Invalid username or password";
    }
  };
});

app.controller("homeCtrl", function ($scope) {
  $scope.loggedInUser = localStorage.getItem("loggedInUser");

  $scope.logout = function () {
    localStorage.removeItem("loggedInUser");
    window.location.href = "login.html"; // Redirect to login page
  };
});
