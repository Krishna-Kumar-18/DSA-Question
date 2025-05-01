#include <bits/stdc++.h>
using namespace std;

int main() 
{
    for(int i=1; i<=10; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}


import cookieParser from "cookie-parser";
import express from "express";
import cors from "cors";
import dotenv from "dotenv";
import { METHODS } from "http";

dotenv.config({});

const app = express();

const SECRET_KEY = "EIEIEIEIEIEI";

const corsOption = {
    origin: 'https://origin-frontend-two.vercel.app',
    credentials:true,
    methods:["POST", "GET", "PUT", "DELETE"],
    allowedHeaders: ['Content-Type', '*']

}

// https://origin-frontend-two.vercel.app/

app.use(express.json());
app.use(express.urlencoded({extended:true}));
app.use(cookieParser());
app.use(cors(corsOption));

app.post('/', (req, res) => {
    res.cookie("token", "my name is this",
        {
            httpOnly:true,
            secure:true,
            sameSite:"none",
            partitioned:true,
            path:'/',
            domain: '.origin-backend-h5rp.onrender.com',
        }
    ).json({
        message:'successfully',
    });
})

const PORT = process.env.PORT || 3000;

app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
})