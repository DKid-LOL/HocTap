<!-- filepath: c:\PhamAnh\HocTap\New folder\test\buoi6\employees.xslt -->
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html" encoding="UTF-8" />

    <xsl:template match="/">
        <html>
            <head>
                <title>Employee List</title>
                <style>
                    table {
                        width: 100%;
                        border-collapse: collapse;
                    }
                    table, th, td {
                        border: 1px solid black;
                    }
                    th, td {
                        padding: 8px;
                        text-align: left;
                    }
                    th {
                        background-color: #f2f2f2;
                    }
                </style>
            </head>
            <body>
                <h1>Employee List</h1>
                <table>
                    <tr>
                        <th>ID</th>
                        <th>Name</th>
                        <th>Position</th>
                        <th>Salary</th>
                    </tr>
                    <xsl:for-each select="Employees/Employee">
                        <tr>
                            <td><xsl:value-of select="ID" /></td>
                            <td><xsl:value-of select="Name" /></td>
                            <td><xsl:value-of select="Position" /></td>
                            <td><xsl:value-of select="Salary" /></td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>