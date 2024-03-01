
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


    try {
    const ownerMailResponse = await fetch(`http://127.0.0.1:8080/getemail/${owner}`, {
        method: 'GET',
        headers: {
            'Content-Type': 'application/json',
            'Access-Control-Allow-Origin': '*'
        }
    });
    const ownerMail = await ownerMailResponse.json();
    console.log("User Email: ", ownerMail);

    let req = {
        "commitMessage": `${answersReceived["What's the Problem Difficulty Level?"]}`,
        "ownerMail": ownerMail,
        "content": `${template}`
    };

    // Now you can use req object here or any further processing
} catch (error) {
    console.log("Error Fetching Email Id of the User", error);
}


    /*
    Author : Naganathan05
    Question Link : http://127.0.0.1:5500/CodeMover/Frontend/HTML/index.html
    */

    