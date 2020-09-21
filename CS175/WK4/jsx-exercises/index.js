import React from "react";
import ReactDOM from "react-dom";

function HelloSpan()
{
    return <span>Hello</span>;
}

function WorldSpan()
{
    return <span>World!</span>;
}

function ExerOne()
{
    return(
        <div className='book'>
            <div className='title'>
                The Title
                </div>
            <div className='author'>The&nbsp;Author</div>
            <ul className='stats'>
                <li className='rating'>5{' '}stars</li>
                <li className='isbn'>12-345678-910</li>
            </ul>
        </div>
    );
}
function ExerFour()
{
    let userName = "root";
    // let userName = undefined;
    // let userName = null;
    // let userName = false;
    return(
        <span>
            {userName ? "Hello, " + userName : "Not logged in!"}
        </span>
    );
}

// function exerciseFive()
// {
//     return(
//         <h1>testing</h1>
//         <h1>testing</h1>
//     );
//     return(
//         [<h1>testing</h1>],<h1>testing</h1>,<h1>testing</h1>];
//     );
//     let m = 14;
//     return(
//         <h1>testing {m && 5; m || 3}</h1>
//     );
//     return(
//         <h1>testing{return}</h1>
//     );
//     return(
//         <h1>{alert("Hello?")}</h1>
//     );
//     return(
//         // <h1>"testing"</h1>
//         <span>{"Testing"}</span>
//     );

// }

function Table()
{
    return(
        <table>
            <tbody>
                <tr>
                    <Data />
                    {/* <td>cats</td>
                    <td>lizards</td>
                    <td>pineapple pizzas</td> */}
                </tr>
            </tbody>
        </table>
    );
}
function Data()
{
    return(
        <>
        <td>dogs</td>
        <td>cichlids</td>
        <td>anchovy pizza</td>
        </>
    );
}
function Main()
{
    return(
    <div>
        <HelloSpan />&nbsp;
        <WorldSpan />
        <ExerOne />
        <ExerFour />
        <Table />
        {/* <ExerFive /> */}
    </div>


    );
}

ReactDOM.render(
    <Main/>,
    document.getElementById("root")
);