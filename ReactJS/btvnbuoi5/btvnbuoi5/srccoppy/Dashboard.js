import React, { useState, useEffect } from 'react';

const Dashboard = () => {
  const [data, setData] = useState([]);

  useEffect(() => {
    const fetchData = async () => {
      try {
        const response = await fetch('https://api.airtable.com/v0/appotNSvSXLDIdvZW/c2307l?maxRecords=100&view=Grid%20view', {
          headers: {
            Authorization: 'Bearer pat67Ci2J8KYG9Iry.0e6ed02a38fe17c9321b1a29ce2db83bc14537ec2610545170d53e4bd8194fcf'
          }
        });

        if (!response.ok) {
          throw new Error('Failed to fetch data');
        }

        const responseData = await response.json();
        setData(responseData.records);
      } catch (error) {
        console.error('Error fetching data:', error);
      }
    };

    fetchData();
  }, []);

  return (
    <div>
      <h1>Dashboard</h1>
      <ul>
        {data.map((record) => (
          <li key={record.id}>
            <strong>Username:</strong> {record.fields.username}, <strong>Password:</strong> {record.fields.password}
          </li>
        ))}
      </ul>
    </div>
  );
};

export default Dashboard;
